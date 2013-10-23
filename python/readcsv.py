import csv

filePath = "/Users/Navgupta/Google Drive/Bhaiya Ticket - Sheet1.csv"
included_cols = [1]

with open(filePath, 'rU' ) 	as 	csvfile:
	data = csv.reader(csvfile ,skipinitialspace = True)
	for row in data:
		print row[0]
