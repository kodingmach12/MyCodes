import urllib
import urllib2
import re
import json

url_yahoo_finance = 'http://in.finance.yahoo.com/q?s=ADBE'

req = urllib2.Request(url_yahoo_finance)
response = urllib2.urlopen(req)
html = response.read()

list_entries = re.findall(r'<span id="yfs_l84_adbe">.*?</span>',html)
for i in list_entries:
    stock_price = re.sub(r'<span id="yfs_l84_adbe">','',i)
    stock_price = re.sub(r'</span>','',stock_price)
    print "\t  ADBE : " +stock_price+" USD"

url_dollar2rupees = 'http://www.dollars2rupees.com/WebApi/ExchangeRate/USD/INR/F6A76A3B-CBA7-46FC-BF7C-1C6DCB280ECF?_=1384265861073'

file_handle = urllib.urlopen(url_dollar2rupees)
response = file_handle.read()
responseJSON =  json.loads(response)
exchange_rate =  responseJSON['C1Value']
print "\t  1 USD = " + exchange_rate + " Rupees "

rsu_count = raw_input("Enter your number of RSU to calculate current value (default is 25) : ")
if not rsu_count:
    rsu_count = 25
print float(rsu_count) * float(stock_price) * float(exchange_rate)
