-- Keep a log of any SQL queries you execute as you solve the mystery.


1.	Bruce
2.	New York City
3.	Robin


-- SELECT COUNT(*) FROM crime_scene_reports WHERE year=2021 AND month=07 AND day=28;

-- SELECT COUNT(*) FROM crime_scene_reports WHERE year=2021 AND month=07 AND day=28 AND street="Hu
mphrey Street";

SELECT * FROM crime_scene_reports WHERE year=2021 AND month=07 AND day=28 AND street="Hu
mphrey Street";

-- SELECT description FROM crime_scene_reports WHERE year=2021 AND month=07 AND day=28 AND street="Hu
mphrey Street";

description:
Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time –
each of their interview transcripts mentions the bakery.

-- .tables
airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

-- SELECT id, license_plate FROM bakery_security_logs WHERE id>=260 AND id<=268;

| id  | license_plate |
+-----+---------------+
| 260 | 5P2BI95       |
| 261 | 94KL13X       |
| 262 | 6P58WS2       |
| 263 | 4328GD8       |
| 264 | G412CB7       |
| 265 | L93JTIZ       |
| 266 | 322W7JE       |
| 267 | 0NTHK55       |
| 268 | 1106N58


-- search for activity in parking lot

SELECT id, hour, minute, license_plate FROM bakery_security_logs WHERE id>=260 AND id<=267;
+-----+------+--------+---------------+
| id  | hour | minute | license_plate |
+-----+------+--------+---------------+
| 260 | 10   | 16     | 5P2BI95       |
| 261 | 10   | 18     | 94KL13X       |
| 262 | 10   | 18     | 6P58WS2       |
| 263 | 10   | 19     | 4328GD8       |
| 264 | 10   | 20     | G412CB7       |
| 265 | 10   | 21     | L93JTIZ       |
| 266 | 10   | 23     | 322W7JE       |
| 267 | 10   | 23     | 0NTHK55       |
+-----+------+--------+---------------+

the query for only the license plate:
SELECT bakery_security_logs.license_plate FROM bakery_security_logs WHERE id>=260 AND id<=267;


-- SELECT name, transcript FROM interviews WHERE year=2021 AND month=07 AND day=28;

from the query result, 3 people had valuable information

| Ruth    |
Sometime within ten minutes of the theft,
I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot,
you might want to look for cars that left the parking lot in that time frame.

| Eugene  |
I don't know the thief's name, but it was someone I recognized.
Earlier this morning, before I arrived at Emma's bakery,
I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

| Raymond |
As the thief was leaving the bakery,
they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight
out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone
to purchase the flight ticket. |

Ruth's lead
there are 2 tables with license plate data, suggest the use of JOIN to find
who left the bakery's parking lot between 1015 am and 1025 am on 28 july 2021

in order to search who the license plate's belong to, it's necessary to JOIN the people and bakery_security_log  ON people.license_plate=bakery_security_logs.license_plate

-- query
SELECT name, people.license_plate FROM people JOIN bakery_security_logs
ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate IN (SELECT bakery_security_logs.license_plate
FROM bakery_security_logs WHERE id>=260 AND id<=267);

result:
+---------+---------------+
|  name   | license_plate |
+---------+---------------+
| Vanessa | 5P2BI95       |
| Vanessa | 5P2BI95       |
| Barry   | 6P58WS2       |
| Barry   | 6P58WS2       |
| Iman    | L93JTIZ       |
| Iman    | L93JTIZ       |
| Sofia   | G412CB7       |
| Sofia   | G412CB7       |
| Luca    | 4328GD8       |
| Luca    | 4328GD8       |
| Diana   | 322W7JE       |
| Diana   | 322W7JE       |
| Kelsey  | 0NTHK55       |
| Kelsey  | 0NTHK55       |
| Bruce   | 94KL13X       |
| Bruce   | 94KL13X       |
+---------+---------------+

following Eugene's testimony...
I query the atm_transactions db

SELECT * FROM atm_transactions WHERE transaction_type="withdraw"
AND year=2021 AND month=07
AND day=28 AND atm_location="Leggett Street";

+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

I must use the results with another table to find which operations happened before 1015 am on that same day

now, to the bank_accounts table...

Use the bank_accounts table to find who withdrew money on that day

First, find the account number for all the people who withdrew money on that day from atm on Leggett Street

SELECT account_number FROM atm_transactions WHERE transaction_type="withdraw" AND year=2021
AND month=07 AND day=28 AND atm_location="Leggett Street";

now, find the id for those people using the bank_accounts table

SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE transaction_type="withdraw" AND year=2021
AND month=07 AND day=28 AND atm_location="Leggett Street");

result of query is:

+-----------+
| person_id |
+-----------+
| 686048    |
| 514354    |
| 458378    |
| 395717    |
| 396669    |
| 467400    |
| 449774    |
| 438727    |
+-----------+

now, to find the name of the 8 people who withdrew money from that atm that day....query the people table

SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE transaction_type="withdraw" AND year=2021
AND month=07 AND day=28 AND atm_location="Leggett Street"));

result:
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
+---------+

now to Raymond's testimony...

query the phone_calls table

SELECT caller FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60;

result:

+----------------+
|     caller     |
+----------------+
| (130) 555-0289 |
| (499) 555-9472 |
| (367) 555-5533 |
| (499) 555-9472 |
| (286) 555-6063 |
| (770) 555-1861 |
| (031) 555-6622 |
| (826) 555-1652 |
| (338) 555-6650 |
+----------------+

now, lets find the identity of the people who made calls with duration of under 60 sec on that day..using the people table

SELECT name, phone_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60);

result:
+---------+----------------+
|  name   |  phone_number  |
+---------+----------------+
| Kenny   | (826) 555-1652 |
| Sofia   | (130) 555-0289 |
| Benista | (338) 555-6650 |
| Taylor  | (286) 555-6063 |
| Diana   | (770) 555-1861 |
| Kelsey  | (499) 555-9472 |
| Bruce   | (367) 555-5533 |
| Carina  | (031) 555-6622 |
+---------+----------------+

we should intersect the results from the analysis of all 3 testimonies

+---------+----------------+
|  name   |  phone_number  |
+---------+----------------+
|
|
|
|
| Diana   | (770) 555-1861 |
|
| Bruce   | (367) 555-5533 |
|
+---------+----------------+

+---------+
|  name   |
+---------+
|    |
|
|
|
|
| Diana   |
| Bruce   |
+---------+

+---------+---------------+
|  name   | license_plate |
+---------+---------------+
|

| Diana   | 322W7JE       |
| Diana   | 322W7JE       |
|
| Bruce   | 94KL13X       |
| Bruce   | 94KL13X       |
+---------+---------------+

..we must now use the second part of Raymond's testimony... use the tables: airport, flights, passengers

first, search the code for fiftyville's airport
SELECT id FROM airports WHERE city="Fiftyville";

second, find first flight out of fiftyville on 29 july 2021
SELECT id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1;

next, from the passengers table..find the passengers on that flight on 20210729..find their passport number

SELECT passport_number FROM passengers WHERE flight_id=(SELECT id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1);

query result:
+-----------------+
| passport_number |
+-----------------+
| 7214083635      |
| 1695452385      |
| 5773159633      |
| 1540955065      |
| 8294398571      |
| 1988161715      |
| 9878712108      |
| 8496433585      |
+-----------------+

now, query the people table to find out the names of the passengers on that flight on 20210729

SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id=(SELECT id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1));

result:
+--------+
|  name  |
+--------+
| Kenny  |
| Sofia  |
| Taylor |
| Luca   |
| Kelsey |
| Edward |
| Bruce  |
| Doris  |
+--------+

2. Now, where is that flight headed to ?

SELECT destination_airport_id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1;

SELECT full_name FROM airports WHERE id=(SELECT destination_airport_id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1);


3. Who did Bruce call on 20210728? Check duration of the call, under 60 sec

SELECT name, phone_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration<60);

query result:
---------+----------------+
|  name   |  phone_number  |
+---------+----------------+
| Kenny   | (826) 555-1652 |
| Sofia   | (130) 555-0289 |
| Benista | (338) 555-6650 |
| Taylor  | (286) 555-6063 |
| Diana   | (770) 555-1861 |
| Kelsey  | (499) 555-9472 |
| Bruce   | (367) 555-5533 |
| Carina  | (031) 555-6622 |
+---------+----------------+

SELECT receiver FROM phone_calls WHERE caller="(367) 555-5533" AND year=2021 AND month=7 AND day=28 AND duration<60;

+----------------+
|    receiver    |
+----------------+
| (375) 555-8161 |
+----------------+

SELECT name FROM people WHERE phone_number="(375) 555-8161";

the accomplice is Robin

