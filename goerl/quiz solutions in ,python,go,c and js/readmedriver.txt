pip install psycopg2-binary

This is the best practice approach. Modifying the PostgreSQL driver directly would not be recommended, because it could lead to compatibility issues with other parts of your application or third-party applications that rely on the driver. It's generally best to keep such changes confined to your own application code.
