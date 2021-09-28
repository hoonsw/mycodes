import requests
from bs4 import BeautifulSoup

myid = input("ID : ")
mypasswd = input("PASSWORD : ")

url = 'https://www.dcinside.com'

response = requests.get(url)
bs = BeautifulSoup(response.text,'lxml')
loginForm = bs.find('form',{'id':'login_process'})
csrf_token = loginForm.find_all('input',type='hidden')[2]
csrf_token_key = csrf_token['name']
csrf_token_value = csrf_token['value']

login_url = 'https://dcid.dcinside.com/join/member_check.php'

formdata = {}
formdata['s_url'] = url
formdata['ssl'] = 'Y'
formdata[csrf_token_key] = csrf_token_value
formdata['user_id'] = myid
formdata['pw'] = mypasswd

header = {}
header['User-Agent']='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'
header['referer']=url

rs = requests.session()
rs.post(url,data=formdata,headers=header)

r=rs.get(login_url)
print(r.text)

