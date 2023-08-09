#!/usr/bin/env python3

import requests
url = "https://api.zhunpai.com/v1/api/glm-api"
response = requests.get(url)

if response.status_code == 200:
    data = response.json()
    print(data)

else:
    pass
