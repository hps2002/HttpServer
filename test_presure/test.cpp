#include "../http/http_conn.h"
#include "../http/http_conn.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    http_conn con;
    char *text = "Upgrade-Insecure-Requests: 1\r\n";
    http_conn::HTTP_CODE res =  con.parse_headers(text);
    cout << res << endl;
    return 0;
}