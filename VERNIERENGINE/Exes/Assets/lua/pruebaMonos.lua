pruebaMonos = {
    entities = {"mono1", "mono2", "mono3", "suelo2","camaraPrincipal2", "luz"}
}

luz = {
    Active = true,
    Listener = true,
    Components = {"Transform","Light"},

    Transform = {
        Position = "0,500,0",
        Scale = "1,1,1",
        Rotation = "0,0,0"
    },
	
    Light = {
        LightType = "DIRECTIONAL_LIGHT",
        Distance = 100000,
        Diffuse = "1,1,1",
        Specular = "1,1,1",
        Direction = "1,-1,-1",
        AmbientBool = 1,
        AmbientColor = "0.5,0.5,0.5",
        InnerAngle = 35,
        OuterAngle = 60,
        On = 1
    }
	
}

mono1={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody","MovementPlayer", "MonkeyStats"},

    Transform = {
        Position = "0,300,0",
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
        Position = "0,300,0"
    },
    MovementPlayer = {
        Vel = "10",
        Entity = "camaraPrincipal2"
    },
    MonkeyStats = {
        Lives = 5,
        Speed = 0.8,
        Jump = 0.8
    }
}

mono2={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody","MovementPlayer", "MonkeyStats"},

    Transform = {
        Position = "0,300,0",
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
        Position = "0,300,0"
    },
    MovementPlayer = {
        Vel = "10",
        Entity = "camaraPrincipal2"
    },
    MonkeyStats = {
        Lives = 4,
        Speed = 1,
        Jump = 1
    }
}

mono3={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody","MovementPlayer", "MonkeyStats"},

    Transform = {
        Position = "0,300,0",
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
        Position = "0,300,0"
    },
    MovementPlayer = {
        Vel = "10",
        Entity = "camaraPrincipal2"
    },
    MonkeyStats = {
        Lives = 3,
        Speed = 1.2,
        Jump = 1.2
    }
}

suelo2={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "0,-200,0",
        Scale = "10,10,10",
        Rotation = "-90,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Plane"
    },
    Rigidbody = {
        Type = "Box",
        Mass = "0",
        Scale = "1000,1,1000",
        Position = "0,-200,0"
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

camaraPrincipal2={
    Active = true,
    Listener = true,
    Components = {"Transform","Camera"},

    Transform = {
        Position = "0,0,500",
        Scale = "5,5,5",
        Rotation = "0,90,0"
    },
    
    Camera = {
        PosRel = "0,500,1000",
        Entity = "mono2",
        BackgroundColor = "0.8,0.1,0.3",
        CameraName = "MainCamera2",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1
    }
}