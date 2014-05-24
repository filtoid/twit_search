function request_bearer_token(){
	// Call the twitter api to get a bearer token
	$.ajax({
		url: 'https://api.twitter.com/oauth2/token',
		type: 'GET',
		datatype: 'json',
		success: on_success_bearer_token,
		error: on_error_bearer_token,
		beforeSend: function(xhr) { xhr.setRequestHeader('Authorization', 'Basic ' + token_request); }
	});
}

function on_success_bearer_token(data){
	// Our bearer token has been returned
	var i = 1232;
}

function on_error_bearer_token(error){
	// Something went wrong
	var i = 1232;
}