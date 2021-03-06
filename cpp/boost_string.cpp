#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

using namespace std;

void string_split_demo()
{
    vector<string> vec;
    string str("hello,,world");

    /* split string
     * vec: the place where each part is stored
     * str: string to split
     * boost::is_any_of(): a function return true if one of the chars in arguments is found
     *   
     * By default, every two separators delimit a token
     */
    boost::split(vec, str, boost::is_any_of(","));
    /* result:
     *  0: hello
     *  1:
     *  2: world
     */
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d: %s\n", i, vec[i].c_str());
    }

    /* vec is reused and the old result are overwritten
     * by specifying boost::algorithm::token_compress_on, empty field will
     * be discarded
     */
    boost::split(vec, str, boost::is_any_of(","), boost::algorithm::token_compress_on);
    /* result:
     *  0: hello
     *  1: world
     */
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d: %s\n", i, vec[i].c_str());
    }
}

void string_format_demo()
{
    /* boost::format is a function like sprintf in C but more flexible
     * 
     * Note that the `.str()` is needed when converting format result to a string
     */
    string str = (boost::format("hello, %s %d") % "world" % 23).str();
    printf("%s\n", str.c_str());
}

void string_join_demo()
{
    vector<string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    string str = boost::algorithm::join(vec, ", ");
    printf("%s\n", str.c_str());
}

int main(int argc, char *argv[])
{
    string_split_demo();
    string_format_demo();
    string_join_demo();

    return 0;
}

