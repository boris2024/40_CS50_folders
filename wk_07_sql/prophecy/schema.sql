CREATE TABLE houses2 (
    id INTEGER,
    student_name TEXT,
    head TEXT,
    PRIMARY KEY(id),
    FOREIGN KEY(student_name)
);

CREATE TABLE houses(
    id INTEGER NOT NULL,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE students(
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignments(
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (house_id) REFERENCES houses(id),
    PRIMARY KEY (student_id, house_id)
);