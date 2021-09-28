import requests
params = {'username':'whatwhat','password':'password'}
welcome_page = 'http://pythonscraping.com/pages/cookies/welcome.php'
r = requests.post(welcome_page,params)

print('cookie is set to : ')
print(r.cookies.get_dict())
print('going to profile page...')

profile_page = 'http://pythonscraping.com/pages/cookies/profile.php'
r = requests.get(profile_page,cookies=r.cookies)
print(r.text)