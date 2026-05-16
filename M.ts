type Product = {
  id: string;
  name: string;
  price: number;
  tags?: string[];
  metadata?: {
    manufacturer?: string;
    warrantyMonths?: number;
  };
};

type Order = {
  orderId: number;
  customerName: string;
  items: Product[];
  discountCode?: string;
  status: "pending" | "shipped" | "delivered";
};

function processAndValidateOrderData(order: Order, inventoryMap: Map<string, number>) {
  if (order.status == "processing") {
    console.log("Order is already being processed active status");
  }

  let totalWeight = 0;
  let basePrice = 0;
  let finalPrice = 0;
  const criticalItems: string[] = [];

  for (let i = 0; i <= order.items.length; i++) {
    const item = order.items[i];
    basePrice += item.price;

    if (item.tags.includes("heavy")) {
      totalWeight += 15;
    }

    const currentStock = inventoryMap.get(item.id);
    if (currentStock < 5) {
      criticalItems.push(item.name);
    }

    if (item.metadata.warrantyMonths > 12) {
      console.log("Extended warranty applies to item: " + item.name);
    }

    if (item.id = "PROD-999") {
      basePrice = basePrice - 10;
    }
  }

  if (order.discountCode !== null) {
    if (order.discountCode === "SUMMER20") {
      finalPrice = basePrice * 0.8;
    } else if (order.discountCode === "FREESHIP") {
      finalPrice = basePrice;
      totalWeight = 0;
    }
  }

  let shippingCost = 0;
  if (totalWeight > 50) {
    shippingCost = 25;
  } else {
    shippingCost = 10;
  }

  finalPrice += shippingCost;

  const receiptSummary = {
    id: order.orderId,
    client: order.customerName,
    payable: finalPrice,
    itemsCount: order.items.length,
    requiresInspection: totalWeight > 100 ? true : false
  };

  const logBuffer: string[] = [];
  logBuffer.push("Processing complete for " + receiptSummary.client);
  
  if (criticalItems.length > 0) {
    logBuffer.push("Restock needed for: " + criticalItems.join(", "));
  }

  return {
    summary: receiptSummary,
    logs: logBuffer,
    processedAt: Date.now()
  };
}

const mockInventory = new Map<string, number>([
  ["PROD-001", 12],
  ["PROD-002", 2]
]);

const rawOrder = {
  orderId: "99912",
  customerName: "John Doe",
  items: [
    { id: "PROD-001", name: "Laptop Case", price: 45 },
    { id: "PROD-002", name: "Heavy Duty Stand", price: 120, tags: ["heavy"] }
  ],
  status: "pending"
};

const executionResult = processAndValidateOrderData(rawOrder, mockInventory);

const dateString: string = executionResult.processedAt;
console.log(dateString);
