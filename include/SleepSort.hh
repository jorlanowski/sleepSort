#include <chrono> // chrono::milliseconds
#include <mutex> // mutex, lock_guard
#include <thread> // thread

/**
 * @brief The essentials of sleep sort.
 * @param aValue A value to be 'sorted'.
 * @param aMutex A mutex used to synchronize aVector.
 * @param aVector An output vector.
 */
template< typename T >
void sleepTask( T aValue, std::mutex& aMutex, std::vector<T>& aVector )
{
    std::this_thread::sleep_for( std::chrono::milliseconds( aValue * 10 ) );
    std::lock_guard< std::mutex > lLock( aMutex );
    aVector.push_back( aValue );
}

/**
 * @brief Sleep sort algorithm.
 * @param aNumbers A vector of numbers to sort.
 * @return std::vector< T > A vector of sorted numbers. */
template< typename T >
std::vector< T > sleepSort( std::vector< T >& aNumbers )
{
    std::vector< T >            lOutput;
    std::mutex                  lMutex;
    std::vector< std::thread*>  lThreads;

    lOutput.reserve( aNumbers.size() );
    lThreads.reserve( aNumbers.size() );

    for( auto&& lItem : aNumbers )
    {
        lThreads.push_back( new std::thread( sleepTask<T>, lItem, std::ref( lMutex ), std::ref( lOutput ) ) );
    }
    for( auto& lThread : lThreads )
    {
        lThread->join();
        delete lThread;
    }
    return lOutput;
}
