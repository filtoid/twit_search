twit_search
===========

An app capable of searching twitter for configurable search terms.

Please feel free to use this code for anything you want. Sell it if you like. Just don't incorrectly attribute my name or misrepresent me or my code in anyway. 

Thanks, 

Phil :)
----------------------------------------------------------------------------------

In order to get this code running you will need to upload the files in the html_example to a server capable of parsing PHP.

You will then need to create a file called settings.php with a variable called token_request as such:

<?php
$token_request = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
?>

Where xxxx...xxxxx is your base64 encoded token from the twitter API. Further details on how to set this up to follow.

Then simply go to the index.html and enter the search term you want to search. If you have any problems then please let me know.
