<?php
/**
* The code below has been "borrowed" from John Hurlock's public git hub project:
* https://github.com/jonhurlock/Twitter-Application-Only-Authentication-OAuth-PHP
*
*The following link will link to the page the code has come from:
*
* https://github.com/jonhurlock/Twitter-Application-Only-Authentication-OAuth-PHP/blob/master/Oauth.php
*
*/
include 'settings.php';

header('Content-Type: application/json');

// We need a q var to continue - the search term we are going to use.
if(!isset($_GET['q'])){
	$ary = array( 'status' => 'error: need a q input' );
	echo( json_encode($ary));
	exit();
}
$q = $_GET['q'];

$url = "https://api.twitter.com/oauth2/token"; // url to send data to for authentication
$headers = array( 
    "POST /oauth2/token HTTP/1.1", 
    "Host: api.twitter.com", 
    "User-Agent: my Twitter App v.1",
    "Authorization: Basic ".$token_request."",
    "Content-Type: application/x-www-form-urlencoded;charset=UTF-8", 
    "Content-Length: 29"
); 

$ch = curl_init(); // setup a curl
curl_setopt($ch, CURLOPT_URL,$url); // set url to send to
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers); // set custom headers
curl_setopt($ch, CURLOPT_POST, 1); // send as post
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); // return output
curl_setopt($ch, CURLOPT_POSTFIELDS, "grant_type=client_credentials"); // post body/fields to be sent
$header = curl_setopt($ch, CURLOPT_HEADER, false); // send custom headers
$httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
$retrievedhtml = curl_exec ($ch); // execute the curl
curl_close($ch); // close the curl
$output = explode("\n", $retrievedhtml);
$bearer_token = '';

foreach($output as $line)
{
	if($line === false)
	{
		// there was no bearer token
	}else{
		$bearer_token = $line;
	}
}

// Now we have a token we can make requests with so we can now do searches with it
$bearer_token = json_decode($bearer_token);

$url = "https://api.twitter.com/1.1/search/tweets.json?q=".$q; // url to send data to for authentication
$headers = array( 
    "GET /1.1/search/tweets.json?q=" . $q . " HTTP/1.1", 
    "Host: api.twitter.com", 
    "User-Agent: my Twitter App v.1",
    "Authorization: Bearer ".$bearer_token->{'access_token'}.""
); 

$ch = curl_init(); // setup a curl
curl_setopt($ch, CURLOPT_URL,$url); // set url to send to
curl_setopt($ch, CURLOPT_HTTPGET, true);
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers); // set custom headers
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); // return output
curl_setopt($ch, CURLOPT_VERBOSE, 0);

$header = curl_setopt($ch, CURLOPT_HEADER, 0); // send custom headers
$httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
$res = curl_exec ($ch); // execute the curl
curl_close($ch); // close the curl

echo(json_encode(json_decode($res)));

?>
