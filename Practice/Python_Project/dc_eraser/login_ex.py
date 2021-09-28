import requests
from bs4 import BeautifulSoup as bs

url = 'https://www.dcinside.com'

response = requests.get(url).text
soup = bs(response, 'html.parser')
loginForm = soup.find('form', attrs={'id':'login_process'})
csrf_token = loginForm.find_all('input', attrs={'type':'hidden'})[2]
csrf_token_key = csrf_token['name']
csrf_token_value = csrf_token['value']

login_url = 'https://dcid.dcinside.com/join/member_check.php'

payload = {}
payload['s_url'] = url
payload['ssl'] = 'Y'
payload['user_id'] = 'porkpitch'
payload['pw'] = 'wlgns33'

header = {}
header['Referer'] = url
header['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'

rs = requests.session()
rs.post(url, data=payload, headers=header)

r = rs.get(login_url)

print(r)
