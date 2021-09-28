import requests
from bs4 import BeautifulSoup


header = {}
header['User-Agent']='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36'

mlbteams = ['Minnesota','NY Yankees','Boston','Houston','LA Dodgers','Atlanta','Washington','Colorado','Arizona','Oakland','LA Angels','Texas','Seattle','Chicago Cubs','NY Mets','Philadelphia','Pittsburgh','Cleveland','Tampa Bay','St. Louis','Milwaukee','Cincinnati','Toronto','Baltimore','San Francisco','San Diego','Kansas City','Chicago Sox','Detroit']


for i in range(0,29):
    teamname = mlbteams[i]
    ALL_HR=0
    ALL_RUNS=0
    ALL_AVG=0
    ALL_OPS=0
    for year in range(2005,2015):
        url = 'http://www.espn.com/mlb/stats/team/_/stat/batting/year/'+str(year)
        page = requests.get(url,headers=header)
        bs = BeautifulSoup(page.text,'lxml')
        HR = bs.find('td',text=teamname).next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.get_text()
        RUNS = bs.find('td',text=teamname).next_sibling.next_sibling.next_sibling.get_text()
        AVG = bs.find('td',text=teamname).next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.get_text()
        OPS = bs.find('td',text=teamname).next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.get_text()
        ALL_HR+=int(HR)
        ALL_RUNS+=int(RUNS)
        ALL_AVG+=float(AVG)
        ALL_OPS+=float(OPS)
    print("team : "+teamname)
    print("average HR : "+str(ALL_HR/10))
    print("average RUNS : "+str(ALL_RUNS/10))
    print("average AVG : "+str(ALL_AVG/10))
    print("average OPS : "+str(ALL_OPS/10))
    print("==============================")  
    i+=1


