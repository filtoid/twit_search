function request_bearer_token(){
	var q = $('#search_query').val();
	var urlstr = 'getdata.php?q='+encodeURIComponent(q);
	
	$('#results').html("Loading Results...");

	// Call the twitter api to get a bearer token
	$.ajax({
		url: urlstr,
		type: 'GET',
		datatype: 'json',
		success: on_success_bearer_token,
		error: on_error_bearer_token,
	});
}

function on_success_bearer_token(data){
	// Our bearer token has been returned
	var str = "";
	var colorBlue = "#aaaaff";
	var colorGray = "#bbbbbb";
	var isBlue = true;

	for(var i=0;i<data.statuses.length;i++){
		var status = data.statuses[i].text;
		var line = "<div style='background-color:";
	    	if(isBlue){
			line += colorBlue;
	    	}else{
			line += colorGray;
	    	}	
		if(
		isBlue = !isBlue;
		line += "' ><br>";	
		line += status + "<br></div>";	
		str+=line;		
	}

	$('#results').html(str);
}

function on_error_bearer_token(error){
	// Something went wrong
	$('#results').html("Error: " + error);
}

function extract_link(){
	
}
