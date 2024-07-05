use clap::Parser;
// use rig::place;

/// Program to generate fake identities.
#[derive(Parser, Debug)]
#[command(version, about, long_about = None)]
struct Args {
    /// Target DB type.
    #[arg(short, long)]
    db: String,

    /// import something to the db?
    #[arg(short, long, default_value_t = "")]
    import: Bool,

    /// URL/Filepath to the import data from.
    #[arg(short, long, default_value_t = "")]
    importpath: String,

    /// export the db?
    #[arg(short, long, default_value_t = "")]
    export: Bool,

    /// URL/Filepath to the export the db to.
    #[arg(short, long, default_value_t = "")]
    exportpath: String,

    /// Number of identities to generate.
    #[arg(short, long, default_value_t = 1)]
    count: u8,
}

fn main() {
    let args = Args::parse();

    // // 1. Try to read the target db.
    // if !Ok(connect_db(args.db)) {
    //     // 2. Create a new db.
    //     create_db(args.db);
    // } 
    
    // if args.import != "" {
    //     // 3. Import data from the given file.
    //     import_data(args.import);
    // }

    // if args.export != "" {
    //     // 4. Export data to the given file.
    //     export_data(args.export);
    // }

    for _ in 0..args.count {
        println!("Hello {}!", c.getid());
    }
}