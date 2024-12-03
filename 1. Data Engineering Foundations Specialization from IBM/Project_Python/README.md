## ETL Project: Top 10 Largest Banks by Market Capitalization

This project demonstrates the application of Extraction, Transformation, and Loading (ETL) processes using Python. The goal is to extract data from a webpage, transform it using currency exchange rates, and load it into both a CSV file and a SQL database. This project simulates a real-world scenario where such a pipeline must be run periodically for reporting purposes.

### Project Details

- **Estimated Time:** 60 minutes  
- **Objective:** Compile a list of the top 10 largest banks in the world ranked by market capitalization and convert the data into multiple currencies (GBP, EUR, INR).  
- **Data Source:** [Wikipedia Archive](https://web.archive.org/web/20230908091635/https://en.wikipedia.org/wiki/List_of_largest_banks)  
- **Exchange Rates CSV:** [Exchange Rate File](https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMSkillsNetwork-PY0221EN-Coursera/labs/v2/exchange_rate.csv)  
- **Output Paths:**  
  - CSV File: `./Largest_banks_data.csv`  
  - Database: `Banks.db`  
  - Log File: `code_log.txt`  
  - Database Table: `Largest_banks`  

### Key Tasks

1. **Log Progress**: Track the progress of the ETL pipeline and save it to `code_log.txt`.
2. **Data Extraction**: Scrape tabular data from the provided URL.
3. **Data Transformation**: Add columns for market capitalization in GBP, EUR, and INR using the exchange rates provided.
4. **Data Loading**: Save the transformed data to a CSV file and an SQLite database.
5. **Query Execution**: Run SQL queries on the database for insights and verification.
6. **Log Verification**: Ensure all progress is logged appropriately.
