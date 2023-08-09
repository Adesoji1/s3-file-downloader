import psycopg2
import json
from psycopg2.extras import RealDictCursor

def fetch_data_as_json(query):
    conn = psycopg2.connect(database="your_database", user="your_username", password="your_password", host="localhost", port="5432")
    cursor = conn.cursor(cursor_factory=RealDictCursor)
    cursor.execute(query)
    rows = cursor.fetchall()
    conn.close()
    return json.dumps({"status_code": 200, "data": rows}, default=str)

'''
or

'''


# import json
# from psycopg2.extras import RealDictCursor
# import psycopg2

# def execute_query_return_json(query, conn):
#     cursor = conn.cursor(cursor_factory=RealDictCursor)
#     cursor.execute(query)
#     rows = cursor.fetchall()
#     return json.dumps({"status_code": 200, "data": rows}, default=str)

# # Test it:
# try:
#     conn = psycopg2.connect(database="your_database", user="username", password="password", host="127.0.0.1", port="5432")
#     query = "SELECT * FROM public.user_table"
#     print(execute_query_return_json(query, conn))
# except Exception as e:
#     print(e)

