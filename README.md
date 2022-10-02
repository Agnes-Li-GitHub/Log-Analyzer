# Log-Analyzer
The program will then print out the 5 most popular pages, and the 5 most active users and the corresponding pages they have visited.

### Input
The log file consists of records of 3 types, each record occupies exactly one line. A page record represents a page on the web server. A user record represents a
user that accesses the system. A visiting record represents a visit by the user indicated by the most recent user record. Here is the format.  
Page record: PAGE (page id) (page url)  
User record: USER (user id)  
Visiting record: VISIT (path id)  
  
### Output
Rules: If two pages are equally popular, the pages are ordered lexicographically. If two users visit the same number of pages, the users are ordered by their id ascendingly. Also, the list of pages a user visit must be printed in ascending order.

Example:  
*** 5 most popular pages ***  
36:/msdownload  
32:/ie  
17:/products  
17:/search  
13:/sitebuilder  
*** 5 most active users ***  
23:10068  
-/activeplatform  
-/activeplatform  
-/activex  
-/automap  
... [snipped]  
11:10019  
-/athome  
-/clipgallerylive  
... [snipped]  
-/search  
  
### Assumption
1. The data file always consists of the three types of records only
2. The page ids are unique across all PAGE records
3. The user ids are unique across all USER records
4. The page ids are unique across all VISIT records of a user
5. VISIT records will only appear after the first USER record
6. The page id in a VISIT record appears only after its corresponding PAGE record
7. There will be at least 5 users and 5 pages
