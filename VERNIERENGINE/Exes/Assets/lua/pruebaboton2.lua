pruebaboton2 = {
    entities = {"fondo", "play", "settings", "exit", "camaraPrincipal2"}
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


fondo = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen1",
        Name = "fondomenu",
        X = "0",
        Y = "0",
        W = "1920",
        H = "1080"
    }
}


play = {
    Active = true,
    Listener = false,
    Components = {"Image", "Button1"},
    Image = {
        OverlayName = "imagen2",
        Name = "play",
        X = "120",
        Y = "70",
        W = "512",
        H = "256"
    },
    Button1 = {
        Callback = "menuSeleccion"
    }
}

settings = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen3",
        Name = "settings",
        X = "690",
        Y = "70",
        W = "512",
        H = "256"
    }
}

exit = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen4",
        Name = "exit",
        X = "1264",
        Y = "70",
        W = "512",
        H = "256"
    }
}

camaraPrincipal2={
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
        CameraName = "MainCamera2",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1,
        Sensibilidad = "1"
    }
}


