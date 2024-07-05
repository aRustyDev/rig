mod place {
    #[derive(Debug)]
    struct Place {
        city: String,
        state: String,
        zip: u8,
        areacode: u8,
    }

    fn (place: Place) new() -> Option<Place> {
        Place {
            city: String::new(),
            state: String::new(),
            zip: 0,
            areacode: 0,
        }
    }
}