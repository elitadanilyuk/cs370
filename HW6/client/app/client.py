# 8 lines

import requests

response = requests.get(url="http://localhost:5001/")

print(response.text)
print()