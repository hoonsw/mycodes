import requests
from bs4 import BeautifulSoup

header = {}
header['User-Agent']='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'

mlbteams = ['Minnesota','NY Yankees','Boston','Houston','LA Dodgers','Atlanta','Washington','Colorado','Arizona','Oakland','LA Angels','Texas','Seattle','Chicago Cubs','NY Mets','Philadelphia','Pittsburgh','Cleveland','Tampa Bay','St. Louis','Milwaukee','Cincinnati','Toronto','Baltimore','San Francisco','San Diego','Kansas City','Chicago Sox','Detroit']


for i in range(0,29):
    teamname = mlbteams[i]
    ALL_ERA=0
    ALL_ER=0
    ALL_RUNS=0
    for year in range(2005,2015):
        url = 'http://www.espn.com/mlb/stats/team/_/stat/pitching/year/'+str(year)
        url2 = 'http://www.espn.com/mlb/stats/team/_/stat/pitching/year/'+str(year)
        url3 = 'http://www.espn.com/mlb/stats/team/_/stat/batting/year/'+str(year)
        page = requests.get(url,headers=header)
        bs = BeautifulSoup(page.text,'lxml')
        page2 = requests.get(url2,headers=header)
        bs2 = BeautifulSoup(page2.text,'lxml')
        page3 =requests.get(url3,headers=header)
        bs3 = requests.get(page3.text,'lxml')
        ERA = bs.find('td',text=teamname).next_sibling.next_sibling.next_sibling.next_sibling.get_text()
        ER = bs2.find('td',text=teamname).next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.get_text()
        RUNS = bs3.find('td',text=teamname).next_sibling.next_sibling.next_sibling.get_text()
        ALL_ERA+=float(ERA)
        ALL_ER+=int(ER)
        ALL_RUNS+=int(RUNS)
    print("team : "+teamname)
    print("average ERA : "+str(ALL_ERA/10))
    print("average ER : "+str(ALL_ER/10))
    print("average RUNS/ER"+str(ALL_RUNS/ALL_ER))
    print("==============================")  
    i+=1