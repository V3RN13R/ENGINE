menuseleccionpersonajes = {
    entities = {"fondo1", "carta1", "carta2", "carta3", "camaraPrincipal3", "boton", "foto1", "foto2", "foto3"}
}

dll={
    Active = true,
    Listener = false,
    Components={"Example"},
    Transform = {
        Position = "200,100,0",
        Scale = "2,2,2",
        Rotation = "0,0,0"
    },
    Example={}
}

foto1 = {
    Active = true,
    Listener = false,
    Components = {"Image", "Button1"},
    Image = {
        OverlayName = "monito1",
        Name = "mono1",
        X = "175",
        Y = "242",
        W = "400",
        H = "415"
    },
    
    Button1 = {
        Callback = "jugar1"
    }
}


foto2 = {
    Active = true,
    Listener = false,
    Components = {"Image", "Button1"},
    Image = {
        OverlayName = "monito2",
        Name = "mono2",
        X = "745",
        Y = "242",
        W = "400",
        H = "415"
    },
    
    Button1 = {
        Callback = "jugar2"
    }
}


foto3 = {
    Active = true,
    Listener = false,
    Components = {"Image", "Button1"},
    Image = {
        OverlayName = "monito3",
        Name = "mono3",
        X = "1320",
        Y = "242",
        W = "400",
        H = "415"
    },
    
    Button1 = {
        Callback = "jugar3"
    }
}

fondo1 = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen23",
        Name = "fondoSeleccionPersonajes",
        X = "0",
        Y = "0",
        W = "1920",
        H = "1080"
    }
}


carta1 = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen43",
        Name = "cartaPersonaje1",
        X = "120",
        Y = "200",
        W = "512",
        H = "768"
    }
}

carta2 = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen33",
        Name = "cartaPersonaje2",
        X = "690",
        Y = "200",
        W = "512",
        H = "768"
    }
}

carta3 = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen53",
        Name = "cartaPersonaje3",
        X = "1264",
        Y = "200",
        W = "512",
        H = "768"
    }
}

camaraPrincipal3={
    Active = true,
    Listener = true,
    Components = {"Transform","Camera"},

    Transform = {
        Position = "0,0,0",
        Scale = "5,5,5",
        Rotation = "0,90,0"
    },
    
    Camera = {
        PosRel = "0,100,500",
        BackgroundColor = "0.8,0.1,0.3",
        CameraName = "MainCamera3",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1,
        Sensibilidad = "1"
    }
}


