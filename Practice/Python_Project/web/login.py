import requests
from bs4 import BeautifulSoup


req = requests.session()
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'}

params = {'user_id':'rhythmachine','pw':'wlgns33'}
r = req.post('https://dcid.dcinside.com/join/member_check.php',data=params)


bs = BeautifulSoup(r.text,'html.parser')
myname=bs.find('div','class':'user_name').text
print(myname)

'''
url_mypage='https://dcid.dcinside.com/join_new/member_modify_chk.php'
res = req.get(url_mypage)
res.raise_for_status()

bs = BeautifulSoup(res.text,'html.parser')
print(bs.html.body)
'''