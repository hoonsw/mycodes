import sys
sys.path.append("web\web_class.py")
import requests
from bs4 import BeautifulSoup

class Crawler:
    def getPage(self, url):
        try:
            req = requests.get(url)
        except requests.exceptions.RequestException:
            return None
        return BeautifulSoup(req.text,'html.parser')

    def safeGet(self,pageObj,selector):
        '''
        Beautifulsoup 객체와 선택자를 받아 콘텐츠 문자열을 추출하는 함수
        주어진 선택자로 검색된 결과가 없다면 빈 문자열을 반환합니다
        '''
        selectedElems=pageObj.select(selector)
        if selectedElems is not None and len(selectedElems)>0
            return '\n'.join([elem.get_text() for elem in selectedElems])
        return ''

    def parse(self, site, url): #url을 받아 콘텐츠를 추출합니다
        bs = self.getPage(url)
        if bs is not None:
            title=self.safeGet(bs,site.titleTag)
            body=self.safeGet(bs,site.bodyTag)
            if title!=''and body!='':
                content=Content(url,title,body)
                content.print()