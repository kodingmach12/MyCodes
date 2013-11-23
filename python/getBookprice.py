#/usr/bin/env python

x = raw_nput("Input ISBN Number of Book")        

import re
import lxml.html
from BeautifulSoup import BeautifulSoup
from mechanize import Browser
from stripogram import html2text
br = Browser()
br.open("Page on Idefix")
br.select_form(name="anahtar kelimearama_isbn")
br["isbn"] = x
response = br.submit()
myXml = response.read()
#html2 = get_field(pricerange, html)
#text = html2text(html)
#text2 = text.replace('Image: Page on Ideefixe', '')
#html = "myXml"
soup = BeautifulSoup(myXml)
#x = soup.findall(True)
print soup.find('b', {'class' : 'pricerange'})

#print x
#c = re.compile('<table border="0" cellpadding="0" cellspacing="0" class="fiyat">(.*?)</table>')
#abc = c.findall(c)
#print abc
