# Thanking everyone who wished me on facebook
import requests
import json

#data
AFTER = 121313
TOKEN = "CAACEdEose0cBAA9tvIcx7RUTZBH93UDmbrXNZBOrwfC6avD320lmkg490BXvAoWv58efyudUfZBNGJRiqNUahf62ggx5FbAXB1AUaJMaQX6vj8DIcMIvByDIIIQlaWhraCGfZAo7o6u2OQ7bFy1ZAaRwFBBICI46i44CZCGSZBbfVZAO3FCUOtsez5F5wcMlBqVWiY6uCV7uxwZDZD"
URL = "https://graph.facebook.com/fql"

# def get_posts():
query = (" SELECT post_id, actor_id, message from stream where filter_key  = 'others' AND source_id = me()   AND  created_time  > 86400 LIMIT 200")
payload = { 'q' : query, 'access_token' : TOKEN  }
r =requests.get(URL, params=payload)
print r.status_code
print r.json()
