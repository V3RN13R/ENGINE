pruebatexto = {
    entities = {"texto","texto2",  "camaraPrincipal2"}
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

texto = {
    Active = true,
    Listener = false,
    Components = {"Text"},
    Text = {
        OverlayName = "texto1",
        Name = "Gemstone",
        X = "0",
        Y = "0",
        FontSize = "75",
        Order = "100",
        Text = "Hola 23",
        RT = 0,
        GT = 0,
        BT = 1,
        RD = 1,
        GD = 1,
        BD = 1
    }
}

texto2 = {
    Active = true,
    Listener = false,
    Components = {"Text"},
    Text = {
        OverlayName = "texto2",
        Name = "TURU",
        X = "0",
        Y = "300",
        FontSize = "25",
        Order = "101",
        Text = "Hola 23",
        RT = 1,
        GT = 0,
        BT = 0,
        RD = 0,
        GD = 1,
        BD = 0
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


