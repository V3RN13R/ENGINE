prueba2 = {
    entities = {"cubo1","mono2", "suelo2","camaraPrincipal2", "luz"}
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

cubo1={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody", "Ground", "Destroyable"},

    Transform = {
        Position = "200,100,0",
        Scale = "2,2,2",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Cube"
    },
    Rigidbody = {
        isTrigger = "true",
        Type = "Box",
        Mass = "0",
        Scale = "100,100,100",
        Position = "200,100,0"
    },
    Ground ={

    },
    Destroyable ={

    }
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

mono2={
    Active = true,
    Listener = true,
    Components = {"Player", "Transform","MeshRenderer", "Rigidbody","MovementPlayer", "Health", "Shoot", "SoundComponent"},

    Player = {

    },
    Transform = {
        Position = "0,300,0",
        Scale = "1,1,1",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Sphere"
    },
    Rigidbody = {
        Type = "Sphere",
        Mass = "1",
        Radius = "40",
        Position = "0,300,0"
    },
    MovementPlayer = {
        Vel = "30",
        Entity = "camaraPrincipal2",
        Speed = 1,
        Jump = 1
    },
    Health = {
        Lives = 4
    },
    Shoot={
        File = "bala.lua",
        Name = "bala",
        NameInGame= "banana"
    },
    SoundComponent={
        Shoot = "/Assets/Sounds/shoot.wav",
        Jump = "/Assets/Sounds/jump.wav"
    }
}


suelo2={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody", "Ground"},

    Transform = {
        Position = "0,0,0",
        Scale = "10,10,10",
        Rotation = "-90,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Plane"
    },
    Rigidbody = {
        isTrigger = "false",
        Type = "Box",
        Mass = "0",
        Scale = "1000,1,1000",
        Position = "0, 0,0"
    },
    Ground = {

    }
    
}

bala={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer","RigidBody"},

    Transform = {
        Position = "150, 400,0",
        Scale = "3,3,3",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Sphere"
    },

    Rigidbody = {
        isTrigger = "false",
        Type = "Sphere",
        Mass = "1",
        Radius = "20",
        Position = "150,400,0"
    },
}

camaraPrincipal2={
    Active = true,
    Listener = true,
    Components = {"Transform","Camera", "SoundComponent"},

    Transform = {
        Position = "0,0,0",
        Scale = "5,5,5",
        Rotation = "0,90,0"
    },
    
    Camera = {
        Sensibilidad = "-1",
        PosRel = "0,100,500",
        Entity = "mono2",
        BackgroundColor = "0.8,0.1,0.3",
        CameraName = "MainCamera2",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1
    },
    SoundComponent={
        Music="./Assets/Sounds/main theme.mp3"
    }
}