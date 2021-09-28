import requests
from bs4 import BeautifulSoup
import re

header = {}
header['User-Agent']='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'

url = 'http://www.espn.com/mlb/stats/team/_/stat/batting/year/2005'
page = requests.get(url,headers=header)
bs = BeautifulSoup(page.text,'lxml')

oddrow = bs.find_all('tr',attrs={'class':re.compile('oddrow team-10-[0-50]+')})
evenrow = bs.find_all('tr',attrs={'class':re.compile('evenrow team-10-[0-50]+')})
for data in oddrow.find_all('td'):
    print(data.get_text())


