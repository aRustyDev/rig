use rusqlite::{Connection, Result};

enum db_type {
    SQLITE,
    POSTGRESQL,
    MYSQL,
    MARIADB,
    MONGODB,
}

enum table {
    NAMES,
    STREET,
    LOCDATA,
}

fn connect(db: db_type) -> Result<Connection> {
    match db {
        db_type::SQLITE => {
            let conn = Connection::open_in_memory()?;
            conn.execute(
                "CREATE TABLE names (
                    name   TEXT CHECK(name <> lower(name)) PRIMARY KEY,
                    fml    INT NOT NULL,
                    gender TEXT CHECK( pType IN ('Male','Neutral','Female') ) NOT NULL 
                )
                CREATE TABLE street (
                    name TEXT CHECK(name <> lower(name)) PRIMARY KEY
                )
                CREATE TABLE locdata (
                    id       TEXT PRIMARY KEY,
                    city     TEXT NOT NULL,
                    state    TEXT NOT NULL,
                    zip      INT NOT NULL,
                    areacode INT NOT NULL
                )",
                (), // empty list of parameters.
            )?;
            Ok(conn)
        }
        db_type::POSTGRESQL => {
            let conn = Connection::open_in_memory()?;
            Ok(conn)
        }
        db_type::MYSQL => {
            let conn = Connection::open_in_memory()?;
            Ok(conn)
        }
        db_type::MARIADB => {
            let conn = Connection::open_in_memory()?;
            Ok(conn)
        }
        db_type::MONGODB => {
            let conn = Connection::open_in_memory()?;
            Ok(conn)
        }
    }
}

fn (c: Connection) insert(table: table) -> Result<()> {
    match table {
        table::NAMES => {
            c.execute(
                "INSERT INTO names (name, fml, gender) VALUES (?1, ?2, ?3)",
                (&self.name, &self.fml, &self.gender),
            )?;
        }
        table::STREET => {
            c.execute(
                "INSERT INTO street (name) VALUES (?1)",
                (&self.name),
            )?;
        }
        table::LOCDATA => {
            let mut hasher = Sha1::new();
            hasher.update(fmt.sprintf("{}{}{}{}", &self.city, &self.state, &self.zip, &self.areacode).as_bytes());
            let result = hasher.finalize();
            c.execute(
                "INSERT INTO locdata (id, city, state, zip, areacode) VALUES (?1, ?2, ?3, ?4, ?5)",
                (&result[..], &self.city, &self.state, &self.zip, &self.areacode),
            )?;
        }
    }
    Ok(())
}

fn (c: Connection) select(table: table) -> Result<()> {
    match table {
        table::NAMES => {
            let mut stmt = c.prepare("SELECT * FROM person")?;
            let person_iter = stmt.query_map([], |row| {
                Ok(Person {
                    id: row.get(0)?,
                    name: row.get(1)?,
                    data: row.get(2)?,
                })
            })?;
        }
        table::STREET => {
            let mut stmt = c.prepare("SELECT * FROM person")?;
            let person_iter = stmt.query_map([], |row| {
                Ok(Person {
                    id: row.get(0)?,
                    name: row.get(1)?,
                    data: row.get(2)?,
                })
            })?;
        }
        table::LOCDATA => {
            let mut stmt = c.prepare("SELECT * FROM person")?;
            let person_iter = stmt.query_map([], |row| {
                Ok(Person {
                    id: row.get(0)?,
                    name: row.get(1)?,
                    data: row.get(2)?,
                })
            })?;
        }
    }
    Ok(())
}