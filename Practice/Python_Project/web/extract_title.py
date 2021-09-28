import requests
from bs4 import BeautifulSoup

session = requests.Session()
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'}

def dctitle(max_pages):
    page=0
    while page<max_pages:
        url = 'https://gall.dcinside.com/board/lists?id=comic_new1&page='+str(page+1)
        req = session.get(url,headers=headers)
        bs = BeautifulSoup(req.text,'lxml')
        titleandname = bs.find_all('tr',{'class':'ub-content us-post'})
        for every in titleandname:
            print(every.a.get_text(),'|||||||||||||||||||||||',print(every.span.get_text()))
        page+=1

number = input("to what pages : ")
dctitle(int(number))
