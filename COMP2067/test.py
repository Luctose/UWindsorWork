kv = [{'k': {'v': 2}}, {'k': {'v': 15}}, {'k': {'v': 8}}]
kv.sort(key=lambda e: e['k']['v'], reverse=True)
print(kv)
