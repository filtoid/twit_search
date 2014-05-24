function request_bearer_token(){
	// Call the twitter api to get a bearer token
	$.ajax({
		url: 'https://api.twitter.com/oauth2/token',
		type: 'POST',
		datatype: 'json',
		success: on_success_bearer_token,
		error: on_error_bearer_token,
		beforeSend: function() { xhr.setRequestHeader('Authorization', 'Basic '); }
	});
}

function on_success_bearer_token(data){
	// Our bearer token has been returned
	
}

function on_error_bearer_token(error){
	// Something went wrong
	
}