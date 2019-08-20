//
//g++ boost_test.cpp -std=c++11 -lboost_system -lboost_thread
#include <boost/asio.hpp>
#include <iostream>

#define Test_1 0
#define Test_2 0
#define Test_3 0
#define Test_4 0
#define Test_5 0
#define Test_6 1 

#if Test_6
#include <boost/thread.hpp>
boost::asio::io_service io_service;

void WorkerThread()
{
    std::cout << "thread start\n";
    io_service.run();
    std::cout << "thread Finish\n";
}
#endif

int main() {

#if Test_1

    boost::asio::io_service io_service;

    io_service.run();

    std::cout << "do u reckon this line display?" << std::endl;

#endif

#if Test_2

    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    io_service.run();

    std::cout << "do u reckon this line display?" << std::endl;

#endif

#if Test_3
    boost::asio::io_service io_service;

    for(int x = 0; x <42; ++x)
    {
        io_service.poll();
        std::cout << "Counter: "<< x << std::endl;
    }


#endif

#if Test_4
    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    for(int x = 0; x <42; ++x)
    {
        io_service.poll();
        std::cout << "Counter: "<< x << std::endl;
    }


#endif

#if Test_5
    boost::asio::io_service io_service;
    std::shared_ptr< boost::asio::io_service::work > work(
            new boost::asio::io_service::work( io_service )
            );

    work.reset();

    io_service.run();

    std::cout << "do u reckon this line display?" << std::endl;
#endif

#if Test_6
    std::shared_ptr< boost::asio::io_service::work > work(
            new boost::asio::io_service::work( io_service )
            );

    std::cout << "press [return] to exit." << std::endl;

    boost::thread_group worker_threads;
    for( int x = 0; x < 4; ++x )
    {
        worker_threads.create_thread( WorkerThread );
    }

    std::cin.get();

    io_service.stop();

    worker_threads.join_all();
#endif

    return 0;
}
