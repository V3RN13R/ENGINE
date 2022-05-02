bala={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer","Rigidbody","BananaMovement"},

    Transform = {
        Position = "0,100,0",
        Scale = "1,1,1",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Sphere"
    },

    Rigidbody = {
        isTrigger = "true",
        Type = "Sphere",
        Mass = "1",
        Radius = "10",
        Position = "0,100,0"
    },
    BananaMovement = {
        TTL = "2",
        Speed = "500",
        Disparador = "camaraPrincipal2"       
    }
}