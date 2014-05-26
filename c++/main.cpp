#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

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


  
  Json::Value root;   // will contains the root value after parsing.
  //Json::Reader reader;

  return 0;
}

