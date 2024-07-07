#include <iostream>
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/core.hpp>
#include <matplot/matplot.h>
#include <vector>
#include <chrono>
#include <filesystem>

class GetLossData : public ens::ProgressBar{
private:
    std::vector<double>& loss_data_value;
    std::vector<double>& loss_data_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    std::chrono::duration<double> totalTime;
public:

    GetLossData(std::vector<double>& loss_data_value,std::vector<double>& loss_data_time,const size_t widthIn = 70,std::ostream& output = arma::get_cout_stream()) 
    : ens::ProgressBar(widthIn,output), loss_data_value(loss_data_value),loss_data_time(loss_data_time){
        // do nothing
    }

    template<typename OptimizerType, typename FunctionType, typename MatType>
    bool EndEpoch(OptimizerType& opt,
    FunctionType& fn,
    const MatType& co,
    const size_t epoch,
    const double objective)
    {   
        this->endTime = std::chrono::high_resolution_clock::now();
        this->totalTime = std::chrono::duration<double>(this->endTime - this->startTime);
        this->loss_data_value.push_back(objective);
        this->loss_data_time.push_back(
            this->totalTime.count()
        );
        this->output.flush();
        return false;
    }

};

int main(){

    // male (1,0) female (0,1)

    std::string current_path = std::filesystem::current_path().string();
    arma::mat train_data;
    arma::mat test_data;

    mlpack::data::Load("Training-set.csv",train_data,true,false,mlpack::data::FileType::CSVASCII);
    mlpack::data::Load("Test-set.csv",test_data,true,false,mlpack::data::FileType::CSVASCII);

    // Split the labels from the training set and testing set respectively.
    // Decrement the labels by 1, so they are in the range 0 to (numClasses - 1).
    arma::mat train_labels = train_data.cols(train_data.n_cols - 2,train_data.n_cols-1);
    arma::mat test_labels = test_data.cols(test_data.n_cols - 2,test_data.n_cols-1);
    train_data.shed_col(train_data.n_cols - 2);
    test_data.shed_col(test_data.n_cols - 2);

    train_data = arma::trans(train_data);
    // train_data = (train_data - train_data.min()) / (train_data.max() - train_data.min()); 
    train_labels = arma::trans(train_labels);

    test_data = arma::trans(test_data);
    // test_data = (test_data - test_data.min()) / (test_data.max() - test_data.min()); 
    test_labels = arma::trans(test_labels);

    // Initialize the network.
    mlpack::FFN<
        mlpack::CrossEntropyError
    > model;
    model.Add<mlpack::Linear>(2);
    model.Add<mlpack::Sigmoid>();
    model.Add<mlpack::Linear>(4);
    model.Add<mlpack::Sigmoid>();
    model.Add<mlpack::Linear>(2);
    model.Add<mlpack::Softmax>();

    // ens::Adam optimizer;
    // optimizer.MaxIterations() = 0;
    std::vector<double> loss_values;
    std::vector<double> loss_times;
    model.Train(
        train_data,
        train_labels,
        // optimizer,
        ens::ProgressBar(),
        ens::Report(0.1),
        GetLossData(loss_values,loss_times)
    );

    std::cout << "Predict\n";
    // Use the Predict method to get the predictions.
    arma::mat predictionTemp;
    model.Predict(test_data, predictionTemp);

    std::cout << predictionTemp.t() << "\n";

    matplot::plot(loss_times, loss_values, "-o")->line_width(3);
    matplot::title("Training Loss/Times (sec)");
    matplot::xlabel("Time in sec");
    matplot::ylabel("loss");
    matplot::show();

}

