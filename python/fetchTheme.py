import urllib
# params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})
# https://kuler.adobe.com/api/v2/themes?filter=public&startIndex=0&maxNumber=10&sort=like_count&time=all&metadata=public&
# x-api-key=7810788A1CFDC3A717C58F96BC4DD8B4
params = urllib.urlencode({	 'startIndex'    : 0, 
				'maxNumber'  : 36, 
				     'filter'   : 'public',
				'x-api-key'     : '7810788A1CFDC3A717C58F96BC4DD8B4'
			})
f = urllib.urlopen("http://kuler.adobe.com/api/v2/themes?%s" % params)
print f.read()