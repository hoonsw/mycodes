from bs4 import BeautifulSoup
import requests


url = 'https://www.dcinside.com'

header = {}
header['User-Agent']='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'
header['referer']=url

param = {}
param['PHPSESSKEY'] = '2a9bb1c66478a80138eeac4dce0b8ec5'

page=input('page : ')
gallog_url = 'https://gallog.dcinside.com/porkpitch/posting?p='+page

response = requests.get(url, cookies=param,headers=header)
gallog_response = requests.get(gallog_url,cookies=param,headers=header)
print(gallog_response.text)