#include <iostream>
#include <sstream>
#include <vector>

#include "SleepSort.hh"

typedef unsigned int UsedType;

/** 
 * @brief Funcion that parses char array to vector of numbers.
 */
template< typename T >
std::vector< T > parse( int aSize, char** aChars )
{
    std::vector< T > lVector;
    lVector.reserve( aSize - 1 );
    for( auto i = 1; i < aSize; ++i )
    {
        T                   lItem;
        std::istringstream  lStream( *(aChars+i) );

        lStream >> lItem;
        lVector.push_back( lItem ); 
    }
    return lVector;
}

int main( int argc, char **argv )
{
    if ( argc == 1 )
    {
        return EXIT_FAILURE;
    }
    if ( *argv[argc-1] != '0' )
    {
        return EXIT_FAILURE;
    }
    auto lVector        = parse< UsedType >( argc, argv );

    auto lOutputVector  = sleepSort< UsedType >( lVector );

    for( auto&& lItem : lOutputVector )
    {
        std::cout << lItem << " ";
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}
