Data1 = read.table("1.out",sep=",")
Data2 = read.table("2.out",sep=",")
Data5 = read.table("5.out",sep=",")
Data10 = read.table("10.out",sep=",")

success1 =colSums(Data1)/50
success2 =colSums(Data2)/50
success5 =colSums(Data5)/50
success10 =colSums(Data10)/50

jpeg("plot.jpg")
x<-seq(1:11)

plot(x, success1,type="l", col="red", xlab="Learning", ylab="Success",ylim=c(-0.5,1.5))

points(x, success2,type="l", col="green")
points(x, success5,type="l", col="blue")

points(x, success10,type="l")

dev.off()
