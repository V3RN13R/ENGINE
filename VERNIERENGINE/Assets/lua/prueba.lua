prueba = {
    entities = {"mono", "suelo", "camaraPrincipal"}
}

mono={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody", "Shoot"},

    Transform = {
        Position = "0,0,0",
        Scale = "10,10,10",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Sphere"
    },
    Rigidbody = {
        Type = "Sphere",
        Mass = "1",
        Radius = "10",
        Position = "0,0,0"
    },
    Shoot = {
        entity = "mono",
        file = "prueba.lua",
        name = "bala",
        prefabName = "bala"
    }
}


suelo={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "0,0,0",
        Scale = "10,10,10",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Plane"
    },
    Rigidbody = {
        Type = "Box",
        Mass = "1",
        Scale = "1,10,10",
        Position = "0,0,0"
    }
    
}

bala={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "-150,-50,0",
        Scale = "5,5,5",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Sphere"
    },
    Rigidbody = {
        Type = "Sphere",
        Mass = "1",
        Radius = "10",
        Position = "0,0,0"
    }
}

camaraPrincipal={
    Active = true,
    Listener = false,
    Components = {"Transform","Camera"},

    Transform = {
        Position = "0,0,500",
        Scale = "5,5,5",
        Rotation = "0,0,0"
    },
    
    Camera = {
        BackgroundColor = "0.2,0.5,0.1",
        CameraName = "MainCamera",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1
    }
}