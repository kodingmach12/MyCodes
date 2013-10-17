import urllib
import json

json_dict = 	{
		    "name" : "My_Theme_july16",
		  
		    "swatches" : [{"mode" : "rgb","values" : [0.1, 0.6, 0.3]},
		                  {"mode" : "rgb","values" : [0.5, 0.67, 0.43]},
		                  {"mode" : "rgb","values" : [0.9, 0.22, 0.7]},
		                  {"mode" : "rgb","values" : [0.87, 0.36, 0.88]},
		                  {"mode" : "rgb","values" : [0.33, 0.44, 0.22]}
		                 ]
		}

# convert json_dict to JSON
json_data = json.dumps(json_dict)

# convert str to bytes (ensure encoding is OK)
post_data = json_data.encode('utf-8')

# we should also say the JSON content type header
headers = {}
headers['Content-Type'] = 'application/json'

# now do the request for a url
req = urllib.request(url, post_data, headers)

# send the request
res = urllib.urlopen(req)

# res is a file-like object
# ...