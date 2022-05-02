prueba = {
    entities = { "suelo", "camaraPrincipal", "fotoprueba"}
}

mono={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody", "MovementPlayer"},

    Transform = {
        Position = "0,100,0",
        Scale = "100,100,100",
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
    MovementPlayer = {
        Vel = "10",
        Entity = "camaraPrincipal",
        Speed = 1,
        Jump = 1
    },
}

camaraPrincipal={
    Active = true,
    Listener = true,
    Components = {"Transform","Camera"},

    Transform = {
        Position = "0,0,0",
        Scale = "5,5,5",
        Rotation = "0,90,0"
    },
    
    Camera = {
        PosRel = "0,500,1000",
        
        BackgroundColor = "0.2,0.5,0.1",
        CameraName = "MainCamera",
        Looking = "0,0,0",
        NearClipDistance = 1,
        FarClipDistance = 100000,
        AspectRatio = 1,
        Sensibilidad = "1"
    }
}

suelo={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "0,-200,0",
        Scale = "1,1,1",
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
    Components = {"Transform","MeshRenderer"},

    Transform = {
        Position = "-150,-50,0",
        Scale = "5,5,5",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Sphere"
    }
}

fotoprueba = {
	Active = true,
	Listener = false,
	Components = {"Transform", "Image"},

	Transform = { 
		Position = "-100, 100, 0",
		Scale = "5,5,5",
		Rotation = "0,0,0"
	},

	Image = {
		Id = "altavoz1"
	}

}