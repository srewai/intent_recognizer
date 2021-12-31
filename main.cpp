// Determine intent of a sentence.
// Input - quoted string as argv[1].
// Output - guessed intent on stdout.
//
// My ideal solution would be to train an ML model
// but since the scope of the task at hand is constrained,
// I am using a simple deterministic approach.


#include <cassert>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>


std::string guess_intent( const std::string & input )
{
    const auto weather_city{ std::regex("atmospheric|sunny|cloudy|rainy|"
                                        "atmosphere|climate|tornadoes|airy|"
                                        "cold|hot|chill|chilling|warm|tornado|"
                                        "temperature|humidity|cloud|cloudy|"
                                        "wind|windy|meteor|air|weather|nice day") };
    const auto weather_general{ std::regex("atmospheric conditions|sunny|"
                                           "cloudy|rainy|atmosphere|climate|"
                                           "tornadoes|airy|cold|hot|chill"
                                           "chilling|warm|tornado|temperature|"
                                           "humidity|cloud|cloudy|wind|windy|"
                                           "meteor|air|weather") };
    const auto facts{ std::regex("fact|something interesting|truth|actuality|" 
                                                            "reality|verity") };

    if( std::regex_search( input, weather_city ) &&
        std::regex_search( input, std::regex("in") ))
    {
        return { "Intent: Get Weather City" };
    }
    else if( std::regex_search( input, weather_general) )
    {
        return { "Intent: Get Weather" };
    }
    else if( std::regex_search( input, facts ) )
    {
        return { "Intent: Get Fact" };
    }
    else
    {
        return { "Intent unknown, let's talk about the weather." };
    }
}


void test()
{
    assert( guess_intent( "What is the weather like today?").compare(
                          "Intent: Get Weather" ) == 0 );
    assert( guess_intent( "What is the weather like in Paris today?").compare(
                          "Intent: Get Weather City" ) == 0 );
    assert( guess_intent( "Tell me an interesting fact.").compare(
                          "Intent: Get Fact" ) == 0 );
}


int main( int argc, char ** argv)
{
    if( argc != 2 )
    {
        std::cerr << "Please call with a quoted sentence or phrase as parameter.";
        return EXIT_FAILURE;
    }

    // Let's work in lowercase only.
    const std::string input_raw{ argv[1] };
    const auto input{ std::accumulate( input_raw.cbegin()
                                    , input_raw.cend()
                                    , std::string{} ) };

    if( std::string{"test"}.compare( input ) == 0 )
    {
        test();
        std::cout << "Tests passed.\n";
        return EXIT_SUCCESS;
    }

    std::cout << guess_intent( input ) << std::endl;
    return EXIT_SUCCESS;
}
