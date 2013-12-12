import csv
import urllib
import urllib2
import re

filePath = "/Users/Navgupta/Google Drive/Bhaiya Ticket - Sheet1.csv"
url = 'http://www.indianrail.gov.in/cgi_bin/inet_pnrstat_cgi.cgi'
included_cols = [1]

def is_valid_pnr(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

with open(filePath, 'rU' ) 	as 	csvfile:
	data = csv.reader(csvfile ,skipinitialspace = True)
	for row in data:
		print row[0] + "  " + row[1] + " " + row[2] + " " + row[3]
		pnr_number =  row[0]
		if  len(pnr_number) == 10 and is_valid_pnr(pnr_number):
			values = {
				'lccp_pnrno1' : pnr_number,
			     	'submit' : 'Wait+For+PNR+Enquiry%21'
			     	}
			data = urllib.urlencode(values)
			req = urllib2.Request(url, data)
			response = ''
			while True:
				try:
					response = urllib2.urlopen(req)
				except:
					pass
				else:
					break

			the_page = response.read()

			list_entries = ''
			try:
				list_entries = re.findall(r'<TD class="table_border_both"><B>.*?</B></TD>',the_page)
			except:
				print "\nEither something is wrong with your PNR number or IRCTC Servers are busy'\n"
				break
			else:
				pass

			current_status = ""

			#print list_entries
			for i in list_entries:
				i = re.sub(r'<TD class="table_border_both"><B>','',i)
				i = re.sub(r'</B></TD>','',i)
				current_status = current_status+i+"  "
			print current_status
