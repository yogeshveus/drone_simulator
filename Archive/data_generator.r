n <- 2000
total_distance <- 3000
number_of_waves <- 3
c <- 2 * pi / total_distance
d <- 1 / 20
e <- 850

t <- seq(0, total_distance, length.out = n)

x <- t + cos(t)
y <- x * d * sin(x * c * number_of_waves) + e

write(
  paste("double x[] = {", paste(x, collapse = ", "), "};"),
  file = "data.cpp"
)
write(
  paste("double y[] = {", paste(y, collapse = ", "), "};"),
  file = "data.cpp",
  append = TRUE
)
