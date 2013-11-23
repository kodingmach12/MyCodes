#!/usr/bin/env python

# https://ims-na1-stg1.adobelogin.com/ims/login/v1/token?
# client_id=CreativeCloudTest1&
# username=navgupta@adobe.com&
# password=nitjsr&
# scope=openid

import urllib
import json
from os import remove
from shutil import move

params = urllib.urlencode({ 'client_id' : 'CreativeCloudTest1',
				'username' : 'navgupta@adobe.com',
				'password' : 'nitjsr',
				'scope' : 'openid'
				})
filehandle = urllib.urlopen("https://ims-na1-stg1.adobelogin.com/ims/login/v1/token?%s" % params)
response = filehandle.read()
# print response
responseJSON =  json.loads(response)
ims_auth_token =  responseJSON['access_token']
# for key,val in response.iteritems():
	# print key,val

filepath = '/Users/Navgupta/code/KulerSDK/KulerSDKSample/Ku_sample.cpp'
newfilepath = '/Users/Navgupta/code/KulerSDK/KulerSDKSample/Ku_sample2.cpp'
filehandle = open( filepath)  # defaults to read mode
newfilehandle = open( newfilepath, 'w')
for linenumber,line in enumerate(filehandle):
	if( linenumber == 48):
		newfilehandle.write('#define ACCESS_TOKEN  "' + ims_auth_token + '"')
	else:
		newfilehandle.write(line)
filehandle.close()
newfilehandle.close()
remove(filepath)
move(newfilepath,filepath)