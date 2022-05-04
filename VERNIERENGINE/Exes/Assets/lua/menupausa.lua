menupausa = {
    entities = { "fondo4", "continue", "ajustes",  "salir", "camaraPrincipal7"}
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

continue = {
    Active = true,
    Listener = false,
    Components = {"Image", "Button1"},
    Image = {
        OverlayName = "imagen2",
        Name = "Continue",
        X = "690",
        Y = "0",
        W = "650",
        H = "650"
    },
    Button1 = {
        Callback = "volver"
    }
}

ajustes = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen3",
        Name = "Ajustes",
        X = "620",
        Y = "320",
        W = "650",
        H = "650"
    }
}

salir = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagen4",
        Name = "Salir",
        X = "650",
        Y = "640",
        W = "650",
        H = "650"
    }
}

camaraPrincipal7={
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
        CameraName = "MainCamera7",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1,
        Sensibilidad = "1"
    }
}



fondo4 = {
    Active = true,
    Listener = false,
    Components = {"Image"},
    Image = {
        OverlayName = "imagenfondo4",
        Name = "fondoSeleccionPersonajes",
        X = "0",
        Y = "0",
        W = "1920",
        H = "1080"
    }
}
