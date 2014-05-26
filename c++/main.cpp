#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <json/json.h>
#include <list>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
list<string> getListStatusStrings(string input);

int main(void)
{
  CURL *curl;
  CURLcode res;
  string readBuffer;

	cout << "Starting the request" << endl;

  curl = curl_easy_init();
  if(curl) {
    	curl_easy_setopt(curl, CURLOPT_URL, "http://www.philjeffes.co.uk/twitter/getdata.php?q=searchterm");
	readBuffer.clear();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	/* Perform the request, res will get the return code */ 
	res = curl_easy_perform(curl);
	/* Check for errors */ 
	if(res != CURLE_OK)
      		fprintf(stderr, "curl_easy_perform() failed: %s\n",
              	curl_easy_strerror(res));
 
    	/* always cleanup */ 
    	curl_easy_cleanup(curl);
  }

	cout << "Finished the request" << endl;
	cout << "Starting the JSON Parsing" << endl;
  
	list<string> statusList = getListStatusStrings(readBuffer);

	for (std::list<string>::iterator it=statusList.begin(); it != statusList.end(); ++it){
    		std::cout << ' ' << *it << endl<< endl;
	}

 	return 0;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/*
*This code has been taken from (and altered from) the sourceforge documentation 
*which can be found here: http://jsoncpp.sourceforge.net/
*/
list<string> getListStatusStrings(string input)
{
	list<string> ret;

	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse( input, root );
	if ( !parsingSuccessful )
	{
	    cout  << "Failed to parse input:\n"
		       << "    " << reader.getFormattedErrorMessages();
	    return ret;
	}

	const Json::Value statuses = root["statuses"];
	for ( int index = 0; index < statuses.size(); ++index )
	{  
	   Json::Value status = statuses[index];
	   ret.push_back( status["text"].asString() );
	}

	return ret;
}

